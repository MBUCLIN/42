(function() {
	document.getElementById("load_all").addEventListener("click", function() {
		var			xhttp = new XMLHttpRequest();
		var			p_exists = document.getElementById("nothing");
		var			div = document.getElementById("picture_took");
		var			already_have = document.getElementsByClassName("last_pictures");

		xhttp.onreadystatechange = function() {
			if (this.readyState === 4) {
				if (this.status === 200) {
					alert("status 200");
					var		imgname = this.responseText.split(":");
					console.log(this.responseText);
					console.log(imgname);
					if (imgname[0] === "Success") {
						if (imgname.length < 2) {
							if (!document.getElementById("nothing")) {
								var		p = document.createElement("p");
								var		content = document.createTextNode("An error occured");

								p.appendChild(content);
								p.id = "nothing";
								document.getElementById("last-picture_div").appendChild(p);
							}
						}
						if (p_exists) {
							div.removeChild(p_exists);
						}
						for (var i = 1; i < imgname.length ; i++) {
							var		img = document.createElement("img");

							img.id = imgname[i];
							img.className = "last_pictures";
							img.src = "resized/" + imgname[i] + ".png";
							img.alt = "resized " + i;
							div.appendChild(img);
						}
					} else {
						if (!document.getElementById("nothing")) {
							var		p = document.createElement("p");
							var		content = document.createTextNode("An error occured");

							p.appendChild(content);
							p.id = "nothing";
							document.getElementById("last-picture_div").appendChild(p);
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
		}
		xhttp.open("POST", "php_script/load_image.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("id=" + ids);
	});
}());
