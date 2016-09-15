(function() {
	var		clicked = 0;
	document.getElementById("disp_log").addEventListener("click", function(object) {
		var		log = document.getElementById("log");

		if (log.style.display !== "block") {
			clicked = 1;
			log.style.display = "block";
		} else if (window.innerWidth <= 500 && clicked === 1) {
			clicked = 0;
			log.style.display = "none";
		}
	});

	window.addEventListener("resize", function() {
		var		log = document.getElementById("log");

		if (window.innerWidth >= 500) {
			clicked = 0;
			log.style.display = "block";
		} else if (window.innerWidth < 500 && clicked === 0) {
			log.style.display = "none";
		}
	});
})();
