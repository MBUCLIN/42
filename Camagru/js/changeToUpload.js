(function() {
	document.getElementById("upload").addEventListener("click", function() {
		var		video = document.getElementById("video_div").style.display = "none";
		var		upload = document.getElementById("upload_div").style.display = "block";
	});
	document.getElementById("toVideo").addEventListener("click", function() {
		var		video = document.getElementById("video_div").style.display = "block";
		var		upload = document.getElementById("upload_div").style.display = "none";
	});
}());
