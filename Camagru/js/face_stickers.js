(function() {

	for (var num = 0; num < 5; num++) {
		var		elem = document.getElementById("face" + num);

		console.log(elem.id);
		elem.addEventListener("change", function(ev) {
			console.log(ev.target.id);
			if (ev.target.checked) {
				for (var i = 0; i < 5; i++) {
					var		box = document.getElementById("face" + i);
					if (box != ev.target) {
						box.disabled = true;
					}
				}
			} else {
				for (var i = 0; i < 5; i++) {
					var		box = document.getElementById("face" + i);
					if (box != ev.target) {
						box.disabled = false;
					}
				}
			}
		});
	}
}());
