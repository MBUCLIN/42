(function() {
	document.getElementById("upload-file").addEventListener("change", function(event) {
		var		file = event.target.files[0];
		var		reader = new FileReader();
		var		output = document.getElementById("uploaded-image");

		reader.addEventListener("load", function() {
			var	dURL = reader.result;
			output.src = dURL;
		});
		if (file) {
			reader.readAsDataURL(file);
		}
	});
}());
