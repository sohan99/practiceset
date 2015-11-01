

function viewpage(pageid){
	if(pageid != 4){
		//document.getElementById("iframe_parent").src = "html/view.html";
	}
	if (pageid == 1){
				document.getElementById("iframe_parent").contentWindow.drwPatientDetails();
	}
	else if(pageid == 2){
		
		document.getElementById("iframe_parent").contentWindow.drwAllergyInfo();
	}
	else if(pageid == 3){
		document.getElementById("iframe_parent").contentWindow.drwMedicalHistory();
	}
}