function onload_hide(){
  $('#PateientDeiailsInID').hide();
}

function drwgrid_chart(ID,pager,obje,menuItem_1,colname_1,caption,val){

  var div = document.getElementById("content_view");
  var w= div.clientWidth;
  var h = div.clientHeight;
  jQuery("#"+ID).GridUnload();
  jQuery("#"+ID).jqGrid({
    // url:'view_patient_details.do',
  	datatype: "json",
     	colNames:colname_1,
     	colModel:menuItem_1,
     	rowNum:10,
     	rowList:[2,20,30],
     	pager: '#'+pager,
     	sortname: 'patientid',
      viewrecords: true,
      sortorder: "desc",
      caption:caption,
      loadonce:true,
      autowidth : true,
     // jsonReader: {cell:""},
      sortname: 'patientid',
      sortorder: 'asc',
      viewrecords: true,
      height: h-20+"px",
      cmTemplate: { title: false }
  });
  jQuery("#"+ID).jqGrid('navGrid','#'+pager,{edit:false,add:false,del:false});

  for(var i=0;i<=obje.length-1;i++){
       jQuery("#"+ID).jqGrid('addRowData',i+1,obje[i]); 
    }
  //$("#"+ID+" > .ui-jqgrid-titlebar").hide();
  //pager2_center

  $("#pager2_center").html("<Button onclick=\"viewInputBox("+val+");\"> insert tuples </button>");

}
    
function drwPatientDetails(){

  str = sendrequestPost("view_patient_details.do","");
  obj = eval(str);
  var menuItem_1 = [
        {name:'patientid',index:'id', width:55},
        {name:'name',index:'invdate', width:90},
        {name:'address',index:'name asc, invdate', width:100},
        {name:'email_id',index:'amount', width:80, align:"right"},
        {name:'ph_number',index:'tax', width:80, align:"right"},    
        {name:'active',index:'total', width:80,align:"right"},   
        {name:'gender',index:'note', width:150, sortable:false}   
      ];

  var colname_1 = ['Patient Id','Name', 'Address', 'Email Id','Ph Number','Status','Gender'];

  var caption = "Patient Details"
  $('#PateientDeiailsInID').hide();
  drwgrid_chart("list2","pager2",obj,menuItem_1,colname_1,caption,1);
  
}



function drwAllergyInfo(){

  str = sendrequestPost("allergy_info.do","");
  obj = eval(str);
  var menuItem_1 = [
        {name:'patientid',index:'id', width:55},
        {name:'allergyid',index:'invdate', width:90},
        {name:'allergy_information',index:'name asc, invdate', width:100}
      ];

  var colname_1 = ['Patient Id','Allergy Id', 'Allergy Information'];

  var caption = "Allergy Details"
  $('#PateientDeiailsInID').hide();

  drwgrid_chart("list2","pager2",obj,menuItem_1,colname_1,caption,2);
  
}


function drwMedicalHistory(){

  str = sendrequestPost("medical_history.do","");
  obj = eval(str);
  var menuItem_1 = [
        {name:'patientid',index:'id', width:55},
        {name:'description',index:'invdate', width:90},
        {name:'vaccination',index:'name asc, invdate', width:100} 
      ];

  var colname_1 = ['Patient Id','Description', 'Vacination'];
  $('#PateientDeiailsInID').hide();
  var caption = "Medical Details"
  drwgrid_chart("list2","pager2",obj,menuItem_1,colname_1,caption,3);
}


function viewInputBox( pageId ){
  $('#input_details1').hide();
  $('#input_details2').hide();
  $('#input_details3').hide();
  if(pageId == 1){
    $('#input_details1').show();
  }
  else if(pageId == 2){
    $('#input_details2').show();
  }
  else if(pageId == 3){
    $('#input_details3').show();
  }
  $('#PateientDeiailsInID').toggle();

}


function saveDetails_patient(){
  var id = $("#p_id").val();
  var name = $("#p_name").val();
  var address = $("#p_address").val();
  var email = $("#p_email").val();
  var ph = $("#p_ph").val();
  var stats = $("#p_stats").val();
  var gender = $("#p_gender").val();
  var str = ""
  str=id+",'"+name+"','"+address+"','"+email+"','"+ph+"',"+stats+",'"+gender+"'"
  var val = sendrequestPost("add_patient.do","val="+str);
  jsondata=eval("(function(){return " +val + ";})()");
  
  if(jsondata.count>0){
    alert(" Successfully added : "+jsondata.count+" rows ")
    drwPatientDetails();
  }
  else 
    alert(jsondata.error)
}

function saveDetails_Allergy(){
  var id = $("#a_pid").val();
  var aid = $("#a_aid").val();
  var info = $("#a_ai").val();
 
  var str = ""
  str=id+","+aid+",'"+info+"'";
  var val = sendrequestPost("add_allergy.do","val="+str);
  jsondata=eval("(function(){return " +val + ";})()");
  
  if(jsondata.count>0){
    alert(" Successfully added : "+jsondata.count+" rows ")
    drwAllergyInfo();
  }
  else 
    alert(jsondata.error)
}

function saveMedical_history(){
  var id = $("#M_pid").val();
  var desc = $("#M_desc").val();
  var vacc = $("#M_Vacc").val();
 
  var str = ""
  str=id+",'"+desc+"','"+vacc+"'";
  var val = sendrequestPost("add_history.do","val="+str);
  jsondata=eval("(function(){return " +val + ";})()");
  
  if(jsondata.count>0){
    alert(" Successfully added : "+jsondata.count+" rows ")
    drwMedicalHistory();
  }
  else 
    alert(jsondata.error)
}
