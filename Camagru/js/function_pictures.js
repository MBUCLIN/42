// ########################################################################## //
// ### This file contain function that are used for the galery.php file   ### //
// ## The list of function that are in the file is :					   ## //
// ##		check_response ::line 15::check for SUCCESS					   ## //
// ##		arrayByBlock ::line 28:: create an array with ID;COM;LIKE	   ## //
// ##		arrayImageLogin ::line 57:: create array with [log1,log2]	   ## //
// ##		arrayImageId ::line 67:: create an array with [id1,id2]		   ## //
// ##		arrayImageComment ::line 77:: create array [commImg1,commImg2] ## //
// ##		arrayImageLike ::line 87:: create array with[logreq,log1,log2] ## //
// ##		createCommentArray :: line 97:: create array [comm1,comm2]     ## //
// ##		createCommentTable :: line 126:: create a table with the comm  ## //
// ##		insertToDocument :: line 152:: insert the ImgDiv in the dom	   ## //
// ########################################################################## //

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
var		arrayByBlock = function(argument) {
	var		open = 0;
	var		close = 0;
	var		sub_level = 0;
	var		i = 0;
	var		array = new Array();

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
	return (array);
}
var		arrayImageLogin = function(argument) {
	var		explode;
	var		arrayLogin = new Array();

	for (var i = 0, l = argument.length; i < l; i++) {
		explode = argument[i].split("[;]");
		arrayLogin[i] = explode[1];
	}
	return (arrayLogin);
}
var		arrayImageId = function(argument) {
	var		explode;
	var		arrayId = new Array();

	for (var i = 0, l = argument.length; i < l; i++) {
		explode = argument[i].split("[;]");
		arrayId[i] = explode[0];
	}
	return (arrayId);
}
var		arrayImageComment = function(argument) {
	var		explode;
	var		arrayComment = new Array();

	for (var i = 0, l = argument.length; i < l; i++) {
		explode = argument[i].split("[;]");
		arrayComment[i] = explode[2];
	}
	return (arrayComment);
}
var		arrayImageLike = function(argument) {
	var		explode;
	var		arrayLike = new Array();

	for (var i = 0, l= argument.length; i < l; i++) {
		explode = argument[i].split("[;]");
		arrayLike[i] = explode[3];
	}
	return (arrayLike);
}
var		createCommentArray = function(comment) {
	var		open = -1, close = 0, sub_level = 0, i = 0;
	var		array = new Array();

	if (comment == "No comment yet")
		return (false);
	while (comment[i]) {
		if (comment[i] == '(' && open == -1) {
			open = i;
		} else if (comment[i] == '(' && open >= 0) {
			sub_level++;
		} else if (comment[i] == ')' && sub_level) {
			sub_level--;
		} else if (comment[i] == ')' && open >= 0 && !sub_level) {
			close = i;
		}
		if (open >= 0 && close) {
			if (array) {
				array[array.length] = comment.substring(open + 1, close);
			} else {
				array[0] = comment.substring(open + 1, close);
			}
			open = -1;
			close = 0;
		}
		i++;
	}
	return (array);
}
var		createCommentTable = function(comment) {
	var		table = document.createElement("table");
	var		arrayComment = createCommentArray(comment);
	var		login, com, explode;
	var		tr;
	var		div = document.createElement("div");

	if (arrayComment == false)
		return (false);
	for (var i = 0, l = arrayComment.length; i < l; i++) {
		tr = document.createElement("tr");
		explode = arrayComment[i].split("{,}");
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
	div.appendChild(table);
	return (div);
}
var		is_userlikepic = function(like) {
	var		i = 1;
	var		array = like.split(',');

	if (array && array[1])
	while (i < array.length) {
		if (array[i] === array[0]) {
			return (1);
		}
		i++;
	}
	return (0);
}
var		insertToDocument = function(id, login, comment, like_list, count) {
	var		div = document.createElement("div");
	var		img = document.createElement("img");
	var		like = document.createElement("button");
	var		nb_like = document.createElement("p");
	var		textarea = document.createElement("textarea");
	var		send_comm = document.createElement("button");
	var		comment_table;
	var		form = document.createElement("form");

	form.method = "POST";
	form.className = "form-comment";
	form.id = id + "-form";
	send_comm.type = "submit";
	send_comm.className = "send-comm";
	send_comm.id = id + "-but_comm";
	send_comm.innerHTML = "Send";
	textarea.id = id + "-comment";
	textarea.className = "textarea-commentary";
	like.className = "like-button";
	like.innerHTML = "Like";
	like.alt = like_list;
	like.id = id + "-" + "like";
	img.src = "images/" + id + ".png";
	img.id = id + "-" + "img";
	img.className = "image-galery";
	div.className = "div-galery";
	div.appendChild(img);
	form.appendChild(textarea);
	form.appendChild(send_comm);
	div.appendChild(form);
	if (is_userlikepic(like_list)) {
		if (like_list.length > 1) {
			var		split = like_list.split(",");
			var		nb = split.length - 1;

			nb_like.style.marginTop = "-25px";
			split = undefined;
			nb_like.id = id + "-nb_like";
			nb_like.className = "nb_like";
			nb_like.innerHTML = nb + "  Likes on this picture.";
			div.appendChild(nb_like);
		}
	} else {
		like.style.marginTop = "-25px";
		div.appendChild(like);
	}
	div.id = id + "-" + "div";
	form.addEventListener("submit", function(Oevent) {
		Oevent.preventDefault();
		submitComment(Oevent, id);
	});
	like.addEventListener("click", function(Oevent) {
		submitLike(Oevent, id, like_list.split(','));
	});
	comment_table = createCommentTable(comment);
	if (comment_table) {
		comment_table.id = id + "-div_table";
		comment_table.className = "table-commentary";
		if (like.parentNode === div) {
			like.style.marginTop = "-225px"
			div.insertBefore(comment_table, like);
		} else if (nb_like.parentNode === div) {
			nb_like.style.marginTop = "-225px";
			div.insertBefore(comment_table, nb_like);
		}
	}
	document.getElementById("galery").appendChild(div);
}
