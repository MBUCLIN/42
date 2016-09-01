function		display_log() {
	var		log = document.getElementById("log");

	console.log(document.body.clientWidth);
	if (document.body.clientWidth < 750) {
		log.style.display = "none";
	} else if (document.body.clientWidth >= 750) {
		log.style.display = "block";
	}
};
window.addEventListener("resize", display_log);
display_log();
