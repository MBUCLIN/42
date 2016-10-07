(function() {
	var		count = 0;
	var		stat = 0;
	function		scrollRequest(scrollY, scrollH, height) {
		if (height + scrollY >= scrollH - 50) {
			if (stat == 0) {
				stat = 1;
				if (loadRequest() != 0) {
					stat = 0;
				}
			}
		}
	};

	function		loadRequest() {
		var		xhttp = new XMLHttpRequest();
		var		status = document.getElementById("status");

		xhttp.onreadystatechange = function() {
			if (this.readyState === 4) {
				if (this.status === 200) {
					if (!check_response(this.responseText)) {
						var		cpy = this.responseText;
						var		img_info = arrayByBlock(cpy);
						var		img_login = arrayImageLogin(img_info);
						var		img_id = arrayImageId(img_info);
						var		img_comment = arrayImageComment(img_info);
						var		img_like = arrayImageLike(img_info);
						var		galery = document.getElementById("galery");
						var		click = document.getElementById("loadMore");

						for (var i = 0, l = img_info.length; i < l; i++) {
							insertToDocument(img_id[i], img_login, img_comment[i], img_like[i], count);
						}
						count += img_info.length;
						status.innerHTML = count.toString() + " images loaded.";
						galery.removeChild(click);
						if (img_info.length)
							galery.appendChild(click);
						return (img_info.length);
					} else {
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

	window.onload = function() {
		var		galery = document.getElementById("galery");
		var		click = document.getElementById("loadMore");

		loadRequest();
	};
	document.getElementById("loadMore").onclick = function() {
		var		scrollY = document.body.scrollTop;
		var		scrollH = document.body.scrollHeight;
		var		height = document.body.clientHeight;

		scrollRequest(scrollY, scrollH, height);
		scrollY = undefined;
		scrollH = undefined;
		height = undefined;
	};
}());
