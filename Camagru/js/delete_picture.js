(function() {
	var		button = document.getElementById("suppr_select");

	button.addEventListener("click", function(ev) {
		var		box = document.getElementsByClassName("checkbox");
		var		request = "ids=";
		var		xhttp = new XMLHttpRequest();
		for (var i = 0, l = box.length; i < l; i++) {
			if (box[i].checked == true) {
				var		id = box[i].id.substring(4, box[i].id.length);

				request += id + ":";
			}
		}
		request = request.substring(0, (request.length - 1));
		xhttp.onreadystatechange = function() {
			if (this.readyState === 4) {
				if (this.status === 200) {
					if (this.responseText !== "Success") {
						alert("Could not delete the image");
						console.log(this.responseText);
					} else {
						var		div = document.getElementById("picture_took");

						request = request.substring(4, request.length);
						request = request.split(':');
						for (var i = 0, l = request.length; i < l; i++) {
							div.removeChild(document.getElementById(request[i]));
							div.removeChild(document.getElementById("lab-" + request[i]));
							div.removeChild(document.getElementById("che-" + request[i]));
						}
					}
				}
			}
		}
		if (request !== "ids=") {
			xhttp.open("POST", "php_script/delete_picture.php", true);
			xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			xhttp.send(request);
		}
	});
}());
