// CHECK IF SUCCESS OR ERROR
var			check_response = function(argument) {
	var		explode = argument.split(";");

	if (explode[0] !== "Success") {
		explode = null;
		argument = null;
		return (-1);
	} else {
		explode = null;
		argument = null;
		return (0);
	}
};
// CREE UN TABLEAU AVEC ID;COMMENT;LIKE
var		arrayByBlock = function(argument) {
	var		open = 0;
	var		close = 0;
	var		sub_level = 0;
	var		i = 0;
	var		array = new Array();

	console.log(array.length);
	while (argument[i]) {
		if (open && close) {
			array[array.length] = argument.substring(open + 1, close);
			open = 0;
			close = 0;
		}
		if (argument[i] == '(' && open == 0) {
			open = i;
		} else if (argument[i] == '(' && open) {
			sub_level++;
		} else if (argument[i] == ')' && sub_level) {
			sub_level--;
		} else if (argument[i] == ')' && open && !sub_level) {
			close = i;
		}
		i++;
	}
	if (open && close) {
		array[array.length] = argument.substring(open + 1, close);
	}
	console.log(array);
	return (array);
}
// RECUPERE LES LOGINS DANS UN TABLEAU [0]login1[1]login2
var		arrayImageLogin = function(argument) {
	var		explode;
	var		arrayLogin = new Array();

	for (var i = 0, l = argument.length; i < l; i++) {
		explode = argument[i].split(";");
		arrayLogin[i] = explode[1];
	}
	return (arrayLogin);
}
// RECUPERE LES ID DANS UN TABLEAU  [0]id1[1]id2 ...
var		arrayImageId = function(argument) {
	var		explode;
	var		arrayId = new Array();

	for (var i = 0, l = argument.length; i < l; i++) {
		explode = argument[i].split(";");
		arrayId[i] = explode[0];
	}
	return (arrayId);
}
// RECUPERE LES COMMENT DANS UN TABLEAU (user{,}comment1)(user{,}comment2)
var		arrayImageComment = function(argument) {
	var		explode;
	var		arrayComment = new Array();

	for (var i = 0, l = argument.length; i < l; i++) {
		explode = argument[i].split(";");
		arrayComment[i] = explode[2];
	}
	return (arrayComment);
}
 // RECUPERE LES LIKE DANS UN TABLEAU name1,name2
var		arrayImageLike = function(argument) {
	var		explode;
	var		arrayLike = new Array();

	for (var i = 0, l= argument.length; i < l; i++) {
		explode = argument[i].split(";");
		arrayLike[i] = explode[3];
	}
	return (arrayLike);
}
// CREATE AN ARRAY [comment1,comment2];
var		createCommentArray = function(comment) {
	var		open = 0, close = 0, sub_level = 0, i = 0;
	var		array = new Array();

	if (comment == "No comment yet")
		return (false);
	while (comment[i]) {
		if (open && close) {
			if (array) {
				array[array.length] = comment.substring(open + 1, close);
			} else {
				array[0] = comment.substring(open + 1, close);
			}
			open = 0;
			close = 0;
		}
		if (comment[i] == '(' && open == 0) {
			open = i;
		} else if (comment[i] == '(' && open) {
			sub_level++;
		} else if (comment[i] == ')' && sub_level) {
			sub_level--;
		} else if (comment[i] == ')' && open && !sub_level) {
			close = i;
		}
		i++;
	}
	return (array);
}
// CREATE A TABLE OF USER | comment
var		createCommentTable = function(comment) {
	var		table = document.createElement("table");
	var		arrayComment = createCommentArray(comment);
	var		login, com, explode;
	var		tr;

	if (arrayComment == false)
		return (false);
	for (var i = 0, l = arrayComment.length; i < l; i++) {
		tr = document.createElement("tr");
		explode = arrayComment.split("{,}");
		login = document.createElement("td");
		com = document.createElement("td");
		login.innerHTML = explode[0];
		com.innerHTML = explode[1];
		tr.appendChild(login);
		tr.appendChild(com);
		table.appendChild(tr);
		login = null;
		com = null;
		tr = null;
	}
	return (table);
}
// INSERT A NEW ELEMENT IN THE DOM
var		insertToDocument = function(id, comment, like_list, count) {
	var		div = document.createElement("div");
	var		img = document.createElement("img");
	var		like = document.createElement("button");
	var		nb_like = document.createElement("p");
	var		input = document.createElement("input");
	var		comment_table;

	input.type = "text";
	input.id = id + "-comment";
	input.className = "input-commentary";
	like.className = "like-button";
	like.innerHTML = "Like";
	like.alt = like_list;
	like.id = id + "-" + "like";
	if (like_list)
		nb_like.innerHTML = like_list.length.toString() + " likes";
	else
		nb_like.innerHTML = "0 like";
	img.src = "images/" + id + ".png";
	img.id = id + "-" + "img";
	img.className = "image-galery";
	div.className = "div-galery";
	div.appendChild(img);
	div.appendChild(like);
	div.appendChild(input);
	comment_table = createCommentTable(comment);
	if (comment_table) {
		comment_table.id = id + "-table";
		comment_table.className = "table-commentary";
		div.appendChild(comment_table);
	}
	div.id = id + "-" + div;
	document.getElementById("galery").appendChild(div);
}
