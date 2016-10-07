(function() {
	document.getElementById("load_all").addEventListener("click", function() {
		var			xhttp = new XMLHttpRequest();
		var			p_exists = document.getElementById("nothing");
		var			div = document.getElementById("picture_took");
		var			already_have = document.getElementsByClassName("last_pictures");

		xhttp.onreadystatechange = function() {
			if (this.readyState === 4) {
				if (this.status === 200) {
					var		imgname = this.responseText.split(":");
					if (imgname[0] === "Success") {
						if (imgname.length < 2) {
							document.getElementById("suppr_select").style.display = "none";
							if (!document.getElementById("nothing")) {
								var		p = document.createElement("p");
								var		content = document.createTextNode("No images found");

								p.appendChild(content);
								p.id = "nothing";
								document.getElementById("last-picture_div").appendChild(p);
							} else {
								document.getElementById("nothing").innerHTML = "No images found";
							}
						} else {
							if (p_exists) {
								document.getElementById("last-picture_div").removeChild(p_exists);
							}
							var		p = document.createElement("p");
							var		content = document.createTextNode("(Click on the picture to delete)");

							p.appendChild(content);
							p.id = "nothing";
							document.getElementById("last-picture_div").appendChild(p);
							for (var i = 1; i < imgname.length ; i++) {
								if (!document.getElementById(imgname[i])) {
									var		img = document.createElement("img");
									var		label = document.createElement("label");
									var		checkbox = document.createElement("input");

									checkbox.type = "checkbox";
									img.id = imgname[i];
									img.className = "last_pictures";
									img.src = "resized/" + imgname[i] + ".png";
									img.alt = "resized " + i;
									label.appendChild(img);
									label.id = "lab-" + imgname[i];
									label.htmlFor = "che-" + imgname[i];
									checkbox.id = "che-" + imgname[i];
									checkbox.className = "checkbox";
									div.appendChild(label);
									div.appendChild(checkbox);
								}
							}
							document.getElementById("suppr_select").style.display = "block";
						}
					} else {
						if (!document.getElementById("nothing")) {
							var		p = document.createElement("p");
							var		content = document.createTextNode("An error occured");

							p.appendChild(content);
							p.id = "nothing";
							document.getElementById("last-picture_div").appendChild(p);
						} else {
							document.getElementById("nothing").innerHTML = "An error occured";
						}
					}
				}
			}
		};
		var		n = 0;
		var		ids;
		while (already_have[n]) {
			if (already_have[n + 1]) {
				ids += already_have[n].id + ":";
			} else {
				ids += already_have[n].id;
			}
			n++;
		}
		xhttp.open("POST", "php_script/load_image.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("id=" + ids);
	});
}());
