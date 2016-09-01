function display_login_info() {
  var   div = document.getElementById("us_info");
  var   vchar = document.createTextNode("valid char : A-Z, a-z, 0-9. ");
  var   vsize = document.createTextNode("to be valid login has to contain atleast 4 characters and no more than 15");

  div.appendChild(vchar);
  div.appendChild(vsize);
};

function display_passwd_info() {
  var   div = document.getElementById("pw_info");
  var   vchar = document.createTextNode("valid char : A-Z, a-z, 0-9 ,");
  var   vsize = document.createTextNode(" To be valid password has to contain atleast 6 characters and no more than 40");
  var   vformat = document.createTextNode("and atleast of one upper/lower and digit characters");
  div.appendChild(vchar);
  div.appendChild(vsize);
  div.appendChild(vformat);
};

function display_conf_passwd_info() {
  var   div = document.getElementById("cpw_info");
  var   text = document.createTextNode("Has to be a perfect match");

  div.appendChild(text);
};

function display_email_info() {
  var   div = document.getElementById("em_info");
  var   text = document.createTextNode("The mail adress has to be valid");

  div.appendChild(text);
};
display_login_info();
display_passwd_info();
display_conf_passwd_info();
display_email_info();
