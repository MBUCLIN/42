document.getElementById("disp_menu").addEventListener("click", function(object) {
	var		little_menu = document.getElementById("hidd_menu");
	var		log = document.getElementById("log");

	if (little_menu.style.display === "none") {
		little_menu.style.display = "block";
		log.style.display = "none";
	} else {
		little_menu.style.display = "none";
	}
});

window.addEventListener("resize", function() {
	var		hidden = document.getElementById("hidd_menu");

	if (window.innerWidth >= 900)
		hidden.style.display = "none";
});
