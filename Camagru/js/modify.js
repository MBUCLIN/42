function		init_input_pass(input) {
	input.pattern = "[A-Za-z0-9]+";
	input.maxLength = "40";
	input.minLength = "6";
	input.type = "password";
	input.value = "password";
	return (input);
};

function		create_passwordInput(ParentNode) {
	var		form = document.createElement("form");
	var		oldPw = document.createElement("input");
	var		newPw = document.createElement("input");
	var		cNewPw = document.createElement("input");
	var		button = document.createElement("button");

	while (ParentNode.firstChild) {
		ParentNode.removeChild(ParentNode.firstChild);
	}
	form.action = "php_script/change_pass.php";
	form.method = "POST";
	form.id = "pass_change";
	form.className = "change";
	button.className = "";
	oldPw = init_input_pass(oldPw);
	newPw = init_input_pass(newPw);
	cNewPw = init_input_pass(cNewPw);
	button.appendChild(document.createTextNode("Modify"));
	form.appendChild(document.createTextNode("Old password :"));
	form.appendChild(oldPw);
	form.appendChild(document.createElement("br"));
	form.appendChild(document.createTextNode("New password :"));
	form.appendChild(newPw);
	form.appendChild(document.createElement("br"));
	form.appendChild(document.createTextNode("Confirm pass :"));
	form.appendChild(cNewPw);
	form.appendChild(document.createElement("br"));
	form.appendChild(button);
	ParentNode.appendChild(form);
	return (ParentNode);
};

function		create_mailinput(ParentNode) {
	var		form = document.createElement("form");
	var		pw = document.createElement("input");
	var		newMail = document.createElement("input");
	var		button = document.createElement("button");

	while (ParentNode.firstChild) {
		ParentNode.removeChild(ParentNode.firstChild);
	}

};

document.getElementById("pass_send").addEventListener("click", function() {
	var		div_pass = document.getElementById("mod_pass");

	div_pass = create_passwordInput(div_pass);
});
