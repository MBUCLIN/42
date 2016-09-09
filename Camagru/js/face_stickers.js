(function() {


	for (var num = 0; num < 5; num++) {
		var		elem_box = document.getElementById("face" + num.toString());

		elem_box.addEventListener("change", function(ev) {
			for (var i = 0; i < 5; i++) {
				var		box = document.getElementById("face" + i.toString());
				var		del = document.getElementById("copy" + i.toString() + "face");


				if (box !== ev.target) {
					box.checked = false;
					if (del) {
						del.remove();
					}
				} else if (box === ev.target) {
					var		image = document.getElementById(i.toString() + "face");
					var		video = document.getElementById("video");

					if (!document.getElementById("copy" + image.id) && box.checked === true) {
						var		copy = image.cloneNode(true);

						copy.style.zIndex = "1";
						copy.style.position = "fixed";
						copy.id = "copy" + ev.target.id;
						copy.style.display = "none";
						document.body.appendChild(copy);
						document.body.addEventListener("mousemove", function(ev) {
							if (copy.style.display) {
								copy.style.display = "block";
							}
								copy.style.top = ev.clientY + 5 + "px";
								copy.style.left = ev.clientX + 5 + "px";
						});
						video.addEventListener("mousedown", function(ev) {
							box.checked = false;
						});

					}
				}
			}

		});
	}
}());
