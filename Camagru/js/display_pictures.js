(function() {
	var		count = 0;
	var		galDiv = document.getElementById("galery");
	galDiv.onscroll = function(ev) {
		console.log(ev.clientX);
		console.log(ev.clientY);
	};
	window.onload = function(ev) {
		var		xhttp = new XMLHttpRequest();
		var		status = document.getElementById("satus");

		xhttp.onreadystatechange = function (ev) {
			if (this.readyState == 4) {
				if (this.status == 200) {
					if (!check_response(this.responseText)) {
						var		imagesId = parseId(imagesId);
						// DO MY LAYOUT
						count += imagesId.length;
					} else {
						alert("An error occure while loading images");
					}
				}
			} else {
				status.innerHTML = "Loading now !!";
			}
		};
		xhttp.open("POST", "php_script/galery.php", false);
		xhttp.send("n=" + count);
	};
}());
