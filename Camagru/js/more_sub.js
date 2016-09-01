function body_maxWidth(min) {
  var   body = document.body.clientWidth;

  if (body <= 900)
    return (0);
  return (1);
};

document.getElementById("more_us").addEventListener("click", function() {
  var     user_disp = document.getElementById("us_info");
  var     pw_disp = document.getElementById("pw_info");
  var     cpw_disp = document.getElementById("cpw_info");
  var     em_disp = document.getElementById("em_info");

	console.debug("clicked");
  if (body_maxWidth(900) === 0)
    return ;
  if (user_disp.style.display === "none" ) {
    if (pw_disp.style.display !== "none") {
      pw_disp.style.display = "none";
    }  else if (cpw_disp.style.display !== "none") {
      cpw_disp.style.display = "none";
    } else if (em_disp.style.display !== "none") {
      em_disp.style.display = "none";
    }
    user_disp.style.display = "block";
  } else {
    user_disp.style.display = "none";
  }
});

document.getElementById("more_pw").addEventListener("click", function() {
  var     user_disp = document.getElementById("us_info");
  var     pw_disp = document.getElementById("pw_info");
  var     cpw_disp = document.getElementById("cpw_info");
  var     em_disp = document.getElementById("em_info");

  if (body_maxWidth(900) === 0)
    return ;
  if (pw_disp.style.display === "none" ) {
    if (user_disp.style.display !== "none") {
      user_disp.style.display = "none";
    }  else if (cpw_disp.style.display !== "none") {
      cpw_disp.style.display = "none";
    } else if (em_disp.style.display !== "none") {
      em_disp.style.display = "none";
    }
    pw_disp.style.display = "block";
  } else {
    pw_disp.style.display = "none";
  }
});

document.getElementById("more_cpw").addEventListener("click", function() {
  var     user_disp = document.getElementById("us_info");
  var     pw_disp = document.getElementById("pw_info");
  var     cpw_disp = document.getElementById("cpw_info");
  var     em_disp = document.getElementById("em_info");

  if (body_maxWidth(900) === 0)
    return ;
  if (cpw_disp.style.display === "none" ) {
    if (user_disp.style.display !== "none") {
      user_disp.style.display = "none";
    }  else if (pw_disp.style.display !== "none") {
      pw_disp.style.display = "none";
    } else if (em_disp.style.display !== "none") {
      em_disp.style.display = "none";
    }
    cpw_disp.style.display = "block";
  } else {
    cpw_disp.style.display = "none";
  }
});

document.getElementById("more_em").addEventListener("click", function() {
  var     user_disp = document.getElementById("us_info");
  var     pw_disp = document.getElementById("pw_info");
  var     cpw_disp = document.getElementById("cpw_info");
  var     em_disp = document.getElementById("em_info");

  if (body_maxWidth(900) === 0)
    return ;
  if (em_disp.style.display === "none" ) {
    if (user_disp.style.display !== "none") {
      user_disp.style.display = "none";
    }  else if (pw_disp.style.display !== "none") {
      pw_disp.style.display = "none";
    } else if (cpw_disp.style.display !== "none") {
      cpw_disp.style.display = "none";
    }
    em_disp.style.display = "block";
  } else {
    em_disp.style.display = "none";
  }
});
