function create_ul_logged(index, text) {
	var		ln_list = ['index.php', 'galery.php', 'profil.php', 'pictures.php'];
	var		elem = document.createElement("ul");
	var		a = document.createElement("a");
	var		disp = document.createTextNode(text);

	a.href = ln_list[index];
	a.name = text + "_ref";
	a.style.textDecoration = "none";
	a.style.color = "red";
	a.appendChild(disp);
	elem.appendChild(a);
	return (elem);
};

function create_list() {
	var		list = ['Home', 'Galery', 'Profil', 'Pictures'];
	var		rolling = document.getElementById("rolling-menu");
	var		hidden = document.getElementById("hidd_menu");
	var		mothElem = document.createElement("li");
	var		childElem;

	for (var i = 0; i < list.length; i++) {
		childElem = create_ul_logged(i, list[i]);
		childElem.name = list[i];
		mothElem.appendChild(childElem);
}
	mothElem.name = "head_list";
	mothElem.id = "list_loggued";
	rolling.appendChild(mothElem);
	hidden.appendChild(mothElem.cloneNode(true));
};
create_list();
