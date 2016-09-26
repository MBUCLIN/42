(function() {
	document.getElementById("sort-by").addEventListener("change", function(event) {
		var		target = event.target;

		if (target.selectedIndex === 2) {
			document.getElementById("hidd-tag").style.display = "block";
		} else {
			document.getElementById("hidd-tag").style.display = "none";
		}
	});
}());
