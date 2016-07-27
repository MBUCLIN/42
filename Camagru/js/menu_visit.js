function create_ul_visit(index, text) {
	var   ln_list = ['index.php', 'galery.php', 'subscribe.php'];
	var   elem = document.createElement("ul");
	var   a = document.createElement("a");
	var   disp = document.createTextNode(text);

	a.href = ln_list[index];
	a.name = text + "_ref";
	a.style.textDecoration = "none";
	a.style.color = "red";
	a.appendChild(disp);
	elem.appendChild(a);
	return (elem);
};

function create_list() {
	var		list = ['Home', 'Galery', 'Subscribe'];
	var		rolling = document.getElementById("rolling-menu");
	var		hidden = document.getElementById("hidd_menu");
	var		mothElem = document.createElement("li");
	var		li = document.getElementById("list_visit");
	var		childElem;

	mothElem.name = "head_list";
	mothElem.id = "list_visit";
	if (li)
		return ;
	for (var i = 0; i < list.length; i++) {
		childElem = create_ul_visit(i, list[i]);
		childElem.name = list[i];
		mothElem.appendChild(childElem);
	}
	rolling.appendChild(mothElem);
	hidden.appendChild(mothElem.cloneNode(true));
};
create_list();
