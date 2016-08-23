document.getElementById("activ").addEventListener("click", function() {
  var     form = document.getElementById("token_form");

  form.action = "valid_account.php";
  form.submit();
});
