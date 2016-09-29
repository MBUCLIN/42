(function() {
	var		count = 0;
	var		galDiv = document.getElementById("galery");
	galDiv.onscroll = function(ev) {
		console.log(ev.clientX);
		console.log(ev.clientY);
	};
	window.onload = function(ev) {
		var		xhttp = new XMLHttpRequest();
		var		status = document.getElementById("status");

		xhttp.onreadystatechange = function (ev) {
			if (this.readyState == 4) {
				status.innerHTML = "Loaded";
				if (this.status == 200) {
					if (!check_response(this.responseText)) {
						console.log(this.responseText);
						var		cpy = this.responseText;
						var		img_info = arrayByBlock(cpy);
						var		img_login = arrayImageLogin(img_info);
						var		img_id = arrayImageId(img_info);
						var		img_comment = arrayImageComment(img_info);
						var		img_like = arrayImageLike(img_info);

						for (var i = 0, l = img_info.length; i < l; i++) {
							insertToDocument(img_id[i], img_login, img_comment[i], img_like[i], count);
						}
						count += img_info.length;
						console.log(count);
						status.innerHTML = count.toString() + " images loaded.";
					} else {
						console.log(this.responseText);
						alert("An error occure while loading images");
					}
				} else {
					alert("We are sorry but their has been an error for your request!");
				}
			} else if (this.readyState == 1) {
				status.innerHTML = "Loading now";
			} else if (this.readyState == 2) {
				status.innerHTML = "Loading now !";
			} else if (this.readyState == 3) {
				status.innerHTML = "Loading now !!";
			}
		};
		xhttp.open("POST", "php_script/galery.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("num=" + count);
	};
}());
