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
		var		images = null;
		var		size = null;
		var		context = canvas.getContext('2d');
		canvas.width = width;
		canvas.height = height;
		canvas.style.display = "block";
		context.drawImage(video, 0, 0, width, height);
		for (var i = 0; i < 5; i++) {
			if (images) {
				images[i] = document.getElementById("copy" + i.toString() + "face");
			} else {
				images = new Array(document.getElementById("copy" + i.toString() + "face"));
			}
			if (images[i]) {
				var		imgx = images[i].offsetLeft - (video.offsetLeft + document.getElementById("video_div").offsetLeft);
				var		imgy = images[i].offsetTop - (video.offsetTop + document.getElementById("video_div").offsetTop);
				if (size) {
					size += i.toString() + "," + imgx.toString() + "," + imgy.toString() + ":";
				} else {
					size = "pos=" + i.toString() + "," + imgx.toString() + "," + imgy.toString() + ":";
				}
			}
		}
		var		photo = canvas.toDataURL('image/png');
		var 	xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
			if (this.readyState === 4 && this.status === 200) {
				console.log(xhttp.responseText);
				alert("Clear and say to user that the image is saved");
			} else if (this.status === 400) {
				alert("The status is 400");
			} else {
				alert("The status is other than 200");
			}
		};
		xhttp.open("POST", "php_script/save_image.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("image=" + photo + "&" + size);
	}, false);
})();
