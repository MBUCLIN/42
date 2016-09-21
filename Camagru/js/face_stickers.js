(function() {
	var		display = document.getElementById("video_div").style.display;

	for (var num = 0; num < 5; num++) {
		var		elem_box = document.getElementById("face" + num.toString());

		elem_box.addEventListener("click", function(ev) {
			for (var i = 0; i < 5; i++) {
				var		box = document.getElementById("face" + i.toString());
				var		del = document.getElementById("copy" + i.toString() + "face");


				if (box !== ev.target) {
					box.checked = false;
					if (del && del.className !== "putted") {
						del.remove();
					}
				} else if (box === ev.target) {
					var		boxcheck = ev.target.checked;
					var		image = document.getElementById(i.toString() + "face");
					var		video = document.getElementById("video");
					var		imageUpload = document.getElementById("uploaded-image");

					if (!document.getElementById("copy" + image.id) && box.checked === true) {
						var		copy = image.cloneNode(true);

						copy.style.zIndex = "1";
						copy.style.position = "fixed";
						copy.id = "copy" + i.toString() + "face";
						copy.style.display = "none";
						document.body.appendChild(copy);
						document.body.addEventListener("mousemove", function(ev) {
							if (copy.className !== "putted") {
								if (copy.style.display) {
									copy.style.display = "block";
								}
								copy.style.top = ev.clientY + 5 + "px";
								copy.style.left = ev.clientX + 5 + "px";
							}
						});
						video.addEventListener("mousedown", function(ev) {
							if (copy.className !== "putted" && boxcheck) {
								var		top = copy.style.top.substr(0, copy.style.top.length - 2);

								top = parseInt(top);
								copy.style.top = top + window.pageYOffset + "px";
								copy.className = "putted";
								copy.style.position = "absolute";
							}
						});
						if (document.getElementById("upload-file").files[0]){
							imageUpload.addEventListener("mousedown", function(ev) {
								if (copy.className !== "putted" && boxcheck) {
									var		top = copy.style.top.substr(0, copy.style.top.length - 2);

									top = parseInt(top);
									copy.style.top = top + window.pageYOffset + "px";
									copy.className = "putted";
									copy.style.position = "absolute";
								}
							});
						}
					}
				}
			}

		});
	}
}());
