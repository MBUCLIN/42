document.getElementById("submit").addEventListener("click", function() {
	var		form = document.getElementById("sub_form");

	form.action = "confirm_subsend.php";
	form.submit();
});
