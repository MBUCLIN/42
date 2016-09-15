document.getElementById("disp_menu").addEventListener("click", function(object) {
	var		little_menu = document.getElementById("hidd_menu");

	if (little_menu.style.display === "none") {
		little_menu.style.display = "block";
	} else {
		little_menu.style.display = "none";
	}
});

window.addEventListener("resize", function() {
	var		hidden = document.getElementById("hidd_menu");

	if (window.innerWidth >= 900)
		hidden.style.display = "none";
});
