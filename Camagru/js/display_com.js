document.getElementById("dispcomm").addEventListener("click", function(eventObject) {
	var			com = document.getElementById("comm");

	if (com.style.height === "15px") {
		com.style.height = "50px";
	} else {
		com.style.height = "15px";
	}
	eventObject.preventDefault();
});
