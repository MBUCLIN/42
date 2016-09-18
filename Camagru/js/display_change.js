(function() {
	var		info = document.getElementById("about-you-information");
	var		pass = document.getElementById("about-you-password");
	var		mail = document.getElementById("about-you-mail");

	document.getElementById("modify-e_mail").addEventListener("click", function() {
		info.style.display = "none";
		mail.style.display = "block";
	});
	document.getElementById("modify-password").addEventListener("click", function() {
		info.style.display = "none";
		pass.style.display = "block";
	});
}());
