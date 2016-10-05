// ########################################################################## //
// ### That file contain the function that are called for events 		  ### //
// ## The list of function is :									  		   ## //
// ## 					submit_comment ::line 9:: send the comm to server  ## //
// ##					actualize_comment ::line 24:: actualize comment	   ## //
// ########################################################################## //

var		submitComment = function(ev, id) {
	var		xhttp = new XMLHttpRequest();
	var		button = ev.target.childNodes[1];
	var		comment = ev.target.childNodes[0];

	if (comment.value.length) {
		xhttp.onreadystatechange = function(ev) {
			actualize_comment(xhttp, comment, button, id);
		};
	}
	xhttp.open("POST", "php_script/save_comment.php", true);
	xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhttp.send("id_img=	" + id + "&comment=" + comment.value);

}
function		actualize_comment(xhttp, comment, button, id) {
	if (xhttp.readyState === 4) {
		if (xhttp.status === 200) {
			console.log(xhttp.responseText);
			if (!check_response(xhttp.responseText)) {
				var		commentary = xhttp.responseText.split(";")[1];
				var		big_div = document.getElementById(id + "-div"), div, table;
				if (!document.getElementById(id + "-div_table")) {
					div = createCommentTable(commentary);
					div.id = id + "-div_table";
					div.className = "table-commentary";
					big_div.appendChild(div);
				} else {
					div = document.getElementById(id + "-div_table");
					table = div.firstChild;
					var		tr = document.createElement("tr");
					var		login, comm, tmp;
					var		td = document.createElement("td");

					tmp = commentary.split("{,}");
					login = document.createElement("td");
					login.appendChild(document.createTextNode(tmp[0].substring(1)));
					comm = document.createElement("td");
					comm.appendChild(document.createTextNode(tmp[1].substring(0, tmp[1].length - 1)));
					tr.appendChild(login);
					tr.appendChild(comm);
					table.appendChild(tr);
				}
				button.innerHTML = "Send";
				comment.value = "";
			} else {
				alert("Failed to save the comment");
				button.innerHTML = "Send";
				comment.value = "";
			}
		} else {
			alert("An error occured");
			button.innerHTML = "Send";
		}
	} else if (xhttp.readyState === 1) {
		button.innerHTML = "Sending .";
	} else if (xhttp.readyState === 2) {
		button.innerHTML = "Sending ..";
	} else if (xhttp.readyState === 3) {
		button.innerHTML = "Sending ...";
	}
}
function		submitLike(ev, id, list) {
	var		xhttp = new XMLHttpRequest();

	xhttp.onreadystatechange = function(ev) {
		actualize_Like(xhttp, id, list.length);
	};
	xhttp.open("POST", "php_script/add_like.php", true);
	xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xhttp.send("id=" + id);
}
function		actualize_Like(xhttp, id, list_len) {
	if (xhttp.readyState === 4) {
		if (xhttp.status === 200) {
			if (!check_response(xhttp.responseText)) {
				var		like = document.getElementById(id + "-like");
				var		div = document.getElementById(id + "-div");
				var		like_number = document.createElement("p");
				var		inner = list_len + "Likes on this picture.";
				if (div && like) {
					div.removeChild(like);
				} else if (div) {
					like_number.innerHTML = inner;
					div.appendChild(like_number);
				}
			} else {
				alert("Fail to like");
			}
		} else {
			alert("An error occured");
		}
	}
}
