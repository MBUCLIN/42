(function () {
	var		stream = false;
	var		video = document.getElementById("video");
	var		canvas = document.getElementById("canvas");
	var		button = document.getElementById("smile");
	var		width = 320;
	var		height = 0;

	navigator.getMedia = (navigator.getUserMedia || navigator.webkitGetUserMedia ||
						navigator.mozGetUserMedia || navigator.msGetUserMedia);
	navigator.getMedia({video:true, audio:false}, function(media) {
		if (navigator.mozGetUserMedia) {
			video.mozSrcObject = media;
		} else {
			var		vendorURL = window.URL || window.webkitURL;
			video.src = vendorURL.createObjectURL(media);
		}
		video.play();
	}, function(err) {
		console.log("Then go upload !\n" + err);
	});
	video.addEventListener("canplay", function(eventObject) {
		if (!stream) {
			height = video.videoHeight / (video.videoWidth/width);
			video.setAttribute('width', width);
			video.setAttribute('height', height);
			canvas.setAttribute('width', width);
			canvas.setAttribute('height', height);
			stream = true;
		}
	}, false);
	button.addEventListener("click", function(eventObject) {
		canvas.width = width;
		canvas.height = height;
		canvas.style.display = "block";
		canvas.getContext('2d').drawImage(video, 0, 0, width, height);
		var		data = canvas.toDataURL('image/png');
		picture.setAttribute('src', data);
	}, false);
})();
