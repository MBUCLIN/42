document.getElementById("dispcomm").addEventListener("click", function(eventObject) {
	var			com = document.getElementById("comm");

	if (com.style.height === "15px") {
		com.style.height = "50px";
	} else {
		com.style.height = "15px";
	}
});
document.getElementById("seeall").addEventListener("click", function(eventObject) {
	var			hidd = document.getElementById("hidd_comm");

	if (!hidd.style.display) {
		hidd.style.display = "block";
		for (var i = 0; i < 10; i++) {
			hidd.style.borderRadius = i;
		} for (var i = 10; i > 0; i--) {
			hidd.style.borderRadius = i;
		}
	}
});
