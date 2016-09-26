(function() {
	function	sendrequest(xhttp, sort, n, tag) {
		xhttp.open("POST", "php_script/galery.php", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		if (sort.selectedIndex < 2 && !tag) {
			xhttp.send("sort=0&n=" + n + "&tag=none");
		} else if (sort.selectedIndex === 2 && tag) {
			xhttp.send("sort=1&n=" + n + "&tag=" + tag);
		}
		xhttp = null;
		sort = null;
		n = false;
		tag = false;
	}
	function	displayImage(path) {
		var		img = document.createElement("img");
		var		galery = document.getElementById("galery");

		img.className = "galery-pic";
		img.alt = "You cannot see it";
		img.src = path;
		galery.appendChild(img);

	}
	var			sort = document.getElementById("sort-by");
	var			xhttp = new XMLHttpRequest();
	var			list = document.getElementById("hidd-tag");
	var			count = document.getElementById("count").innerHTML[0];

	console.log(count);
	xhttp.onreadystatechange = function() {
		if (this.readyState === 4) {
			if (this.status === 200) {
				var		response = this.responseText.split(':');
			}
		}
	};
	if (list.hasChildNodes()) {
		var		node = list.childNodes;

		for (var n = 0, le = node.length; n < le; n++) {
			node[n].addEventListener("click", function(ev) {
				sendrequest(xhttp, sort, ev.target.innerHTML);
			});
		}
	} else {
		sendrequest(xhttp, sort);
		if (!xhttp) {
			console.log("Ahhh okkk");
		}
	}
}());
