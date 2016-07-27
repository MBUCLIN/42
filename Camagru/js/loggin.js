function connect_user() {
  alert("connect");
};

function create_link(text, url, id) {
  var   link = document.createElement("a");
  var   val = document.createTextNode(text);

  link.name = val;
  link.appendChild(val);
  link.id = id;
  link.href = url;
  return (link);
};

function create_input(value, code, type) {
  var  inp = document.createElement("input");

  inp.name = value;
  inp.type = type;
  if (code === 1) {
    inp.style.background = "#dddddd";
  } else {
    inp.style.background = "#ffffff";
  }
  inp.value = value;
  inp.style.marginBottom = "10px";
  return (inp);
};

function create_elements() {
    var   mothElem = document.getElementById("log");
    var   form = document.createElement("form");
    var   sub = document.createElement("button");
    form.id = "loggin";
    form.name = "log_form";
    form.method = "post";
    form.action = "js/connect.js";
    sub.id = "sub";
    sub.name="log_sub";
    sub.appendChild(document.createTextNode("Submit"));
    form.appendChild(create_input("username", 1, "text"));
    form.appendChild(create_input("password", 1, "password"));
    form.appendChild(sub);
    mothElem.appendChild(form);
    mothElem.appendChild(document.createElement("br"));
    mothElem.appendChild(create_link("forgot your password?", "forgot_password.php", "other"));
    mothElem.appendChild(document.createElement("br"));
    mothElem.appendChild(create_link("not subscribe yet?", "subscribe.php", "other"));
};
