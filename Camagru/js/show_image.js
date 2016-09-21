(function() {
	document.getElementById("upload-file").addEventListener("change", function(event) {
		var		file = event.target.files[0];
		var		reader = new FileReader();
		var		output = document.getElementById("uploaded-image");

		alert("change input");
		reader.addEventListener("load", function() {
			alert("reader listener");
			var	dURL = reader.result;
			output.src = dURL;
		});
		if (file) {
			alert("reader as DATA URL");
			reader.readAsDataURL(file);
		}
	});
}());
