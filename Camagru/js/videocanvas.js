(function() {

	function		clear_div(canvas, context) {
		context.clearRect(0, 0, canvas.offsetWidth, canvas.offsetHeight);
		canvas.style.display = "none";
		document.getElementById("save").style.display = "none";
		for (var i = 0; i < 5; i++) {
			var		del = document.getElementById("copy" + i.toString() + "face");
			var		radio = document.getElementById("face" + i.toString());

			if (del) {
				del.className = null;
				del.remove(del);
			}
			radio.checked = false;
		}
	}
	function		size_view(putted) {
		var i = 0, imgx, imgy, size;
		var		context = document.getElementById("canvas").getContext('2d');
		var		video = document.getElementById("video");
		var		n;
		while (putted[i]) {
			if (putted[i]) {
				imgx = putted[i].offsetLeft - (video.offsetLeft + document.getElementById("video_div").offsetLeft);
				imgy = putted[i].offsetTop - (video.offsetTop + document.getElementById("video_div").offsetTop);

				n = putted[i].id[4];
				console.log(n);
				if (size) {
					size += n.toString() + "," + imgx.toString() + "," + imgy.toString() + ":";
				} else {
					size = "pos=" + n.toString() + "," + imgx.toString() + "," + imgy.toString() + ":";
				}
				context.drawImage(putted[i], imgx, imgy, putted[i].clientWidth, putted[i].clientHeight);
			}
			i++;
		}
		return (size);
	}
	var		stream = false;
	var		video = document.getElementById("video");
	var		canvas = document.getElementById("canvas");
	var		button = document.getElementById("smile");
	var		width = 320;
	var		height = 0;

	navigator.getMedia = (navigator.getUserMedia || navigator.webkitGetUserMedia ||
						navigator.mozGetUserMedia || navigator.msGetUserMedia);
	navigator.getMedia({video:true, audio:false}, function(oMedia) {
		if (navigator.mozGetUserMedia) {
			video.mozSrcObject = oMedia;
		} else {
			var		vendorURL = window.URL || window.webkitURL;
			video.src = vendorURL.createObjectURL(oMedia);
		}
		video.play();
	}, function(err) {
		call_upload();
	});
	if (document.getElementById("video_div").style.display !== "none") {
		video.addEventListener("canplay", function(event) {
			if (!stream) {
				height = video.videoHeight / (video.videoWidth/width);
				video.setAttribute('width', width);
				video.setAttribute('height', height);
				canvas.setAttribute('width', width);
				canvas.setAttribute('height', height);
				stream = true;
			}
		}, false);
		button.addEventListener("click", function(event) {
			var		putted = document.getElementsByClassName("putted");
			var		i = 0;
			var		size = null;

			if (putted[0]) {
				var		select = document.getElementById("select");
				var		context = canvas.getContext('2d');
				var		last = document.getElementById("last-picture_div");

				select.style.display = "block";
				canvas.width = width;
				canvas.height = height;
				context.drawImage(video, 0, 0, width, height);
				canvas.style.display = "block";
				document.getElementById("save").style.display = "block";

				var		photo = canvas.toDataURL('image/png');

				size = size_view(putted);
				document.getElementById("save").addEventListener("click", function() {
					var 	xhttp = new XMLHttpRequest();
					var		select = document.getElementById("select");

					xhttp.onreadystatechange = function() {
						if (this.readyState === 4) {
							if (this.status === 200) {
								if (this.responseText !== "Succes") {
									alert("The image failed to be saved");
								}
								console.log(this.responseText);
								var		canvas = document.getElementById("canvas");
								var		context = canvas.getContext('2d');

								size = null;
								select.style.display = "none";
								clear_div(canvas, context);
							}
						}
					};
					if (select.value !== "Choose tag" && size) {
						var		encode = encodeURIComponent(photo);
						xhttp.open("POST", "php_script/save_image.php", true);
						xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
						xhttp.send("image=" + encode + "&" + size + "&tag=" + select.value);
						select.selectedIndex = 0;
					}
				});
			}
		}, false);

		document.getElementById("reset").addEventListener("click", function() {
			var		canvas = document.getElementById("canvas");
			var		context = canvas.getContext('2d');
			var		select = document.getElementById("select");

			select.style.display = "none";
			clear_div(canvas, context);
		});
	}
})();
