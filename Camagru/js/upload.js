(function() {
	function	size_view(putted) {
		var i = 0, imgx, imgy, size;
		var	image = document.getElementById("uploaded-image");
		var n;

		while (putted[i]) {
			if (putted[i]) {
				imgx = putted[i].offsetLeft - (image.offsetLeft + document.getElementById("upload_div").offsetLeft);
				imgy = putted[i].offsetTop - (image.offsetTop + document.getElementById("upload_div").offsetTop);

				n = putted[i].id[4];
				if (size) {
					size += n.toString() + "," + imgx.toString() + "," + imgy.toString() + ":";
				} else {
					size = "pos=" + n.toString() + "," + imgx.toString() + "," + imgy.toString() + ":";
				}
			}
			i++;
		}
		return (size)
	}
	function	clear_div(image) {
		image.src = "";
		for (var i = 0, l = 5; i < l; i++) {
			var		radio = document.getElementById("face" + i.toString());
			var		del = document.getElementById("copy" + i.toString() + "face");

			radio.checked = false;
			if (del) {
				del.remove(del);
			}
		}
	}

	document.getElementById("upload-reset").addEventListener("click", function() {
		var		putted = document.getElementsByClassName("putted");
		var		imageUpload = document.getElementById("uploaded-image");

		clear_div(imageUpload);
	})
	document.getElementById("upload-form").addEventListener("submit", function(event) {
		event.preventDefault();
		var		size = null;
		var		putted = document.getElementsByClassName("putted");
		var		imageUpload = document.getElementById("uploaded-image");
		var		select = document.getElementById("upload-select");

		if (putted[0]) {
			var		xhttp = new XMLHttpRequest();
			size = size_view(putted);

			xhttp.onreadystatechange = function() {
				if (this.readyState === 4) {
					if (this.status === 200) {
						if (this.responseText !== "Success") {
							alert("The image failed to be saved or is not an image");
						}
							clear_div(imageUpload);
					}
				}
			};
			if (select.selectedIndex !== 0 && size) {
				var		encode = encodeURIComponent(imageUpload.src);
				xhttp.open("POST", "php_script/upload_image.php", true);
				xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
				xhttp.send("img=" + encode + "&" + size + "&tag=" + select.value);
				select.selectedIndex = 0;
				size = null;
			}
		}
	});
}());
