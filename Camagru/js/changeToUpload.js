(function() {
	document.getElementById("upload").addEventListener("click", function() {
		var		video = document.getElementById("video_div").style.display = "none";
		var		upload = document.getElementById("upload_div").style.display = "block";

		for (var i = 0, l = 5; i < 5; i++) {
			var		del = document.getElementById("copy" + i.toString() + "face");
			var		radio = document.getElementById("face" + i.toString());

			if (del) {
				del.remove(del);
			}
			radio.checked = false;
		}
	});
	document.getElementById("toVideo").addEventListener("click", function() {
		var		video = document.getElementById("video_div").style.display = "block";
		var		upload = document.getElementById("upload_div").style.display = "none";

		for (var i = 0, l = 5; i < 5; i++) {
			var		del = document.getElementById("copy" + i.toString() + "face");
			var		radio = document.getElementById("face" + i.toString());

			if (del) {
				del.remove(del);
			}
			radio.checked = false;
		}
	});
}());
