
function sendrequestPost(URL,params){	
	var str="";
	var xmlhttp = new XMLHttpRequest();
	if (window.XMLHttpRequest){
		xmlhttp=new XMLHttpRequest();
	}else{
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.onreadystatechange=function(){
		if (xmlhttp.readyState==4 && xmlhttp.status==200){
			str=xmlhttp.responseText+"";
		}
	}
	xmlhttp.open("POST",URL,false);
	xmlhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
	xmlhttp.setRequestHeader("Content-length", params.length);
	xmlhttp.setRequestHeader("Connection", "close");	
	xmlhttp.send(params);
	return str;
}