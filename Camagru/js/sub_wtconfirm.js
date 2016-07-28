function check_strings(user, pass) {
	alert("hoho");
	if (user.length < 4) {
		alert("Login too short");
		return (0);
	} else if (user.length > 15) {
		alert("Login too long");
		return (0);
	} else if (pass.length > 20) {
		alert("Password too long");
		return (0);
	} else if (pass.length < 6) {
		alert("Password too short");
		return (0);
	}
	return (1);
};

function check_emptyness(user, pass, cfpw, mail) {
	if (user.length === 0 || !user) {
		alert("Choose a username !");
		return (0);
	} else if (pass.length === 0 || !pass) {
		alert("Choose a password !");
		return (0);
	} else if (cfpw.length === 0 || !cfpw) {
		alert("Confirm your password");
		return (0);
	} else if (mail.length === 0 || !mail) {
		alert("Enter your E-mail");
		return (0);
	}
	return (1);
};

document.getElementById("submit").addEventListener("click", function() {
	var		user = document.getElementById("user_name").value;
	var		pass = document.getElementById("passwd").value;
	var		cfpw = document.getElementById("conf_passwd").value;
	var		mail = document.getElementById("mail").value;
	var		form = document.getElementById("sub_form");

	if (check_emptyness(user, pass, cfpw, mail) === 0) {
		return ;
	}
	if (user.localeCompare(pass) === 0) {
		alert("You should choose a diferent password !");
		return ;
	} else if (pass.localeCompare(cfpw)) {
		alert("Confirm password has to be an exact match of password");
		return ;
	}
	if (check_strings(user, pass) === 0) {
		return ;
	}
	form.action = "confirm_subsend.php";
	form.submit();
});
