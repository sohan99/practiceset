
CREATE TABLE Patient_Details(
	PatientID int PRIMARY KEY,
	Name varchar(255),
	Address varchar(255),
	Email_id varchar(255),
	Ph_Number varchar(255),
	active int,
	Gender varchar(255)
);


CREATE TABLE Medical_History(
	PatientID int REFERENCES Patient_Details(PatientID),
	Description varchar(400),
	Vaccination varchar(255)
);

CREATE TABLE Allergy_information(
	PatientID int  REFERENCES Patient_Details(PatientID),
	AllergyId int PRIMARY KEY,
	Allergy_information varchar(255)
);


CREATE TABLE Patient_Allergy(
	PatientID int  REFERENCES Patient_Details(PatientID),
	AllergyID int  REFERENCES Allergy_information(AllergyID),
	Name varchar(255),
	Address varchar(255),
	Gender varchar(255),
	Age varchar(255)
);

CREATE TABLE Patient_Master(
	PatientID int  REFERENCES Patient_Details(PatientID),
	AllergyID int  REFERENCES Allergy_information(AllergyID),
	Allergyinformation varchar(255)
);



select * from Patient_Details;
select * from Medical_History;
select * from Allergy_information;
select * from Patient_Allergy;
select * from Patient_Master;



insert into Patient_Details values(01,'sohan','#12manipal','sohan@gmail.com','9123456789',1,'male');
insert into Patient_Details values(02,'sandeep','#13bangalore','sandeep@gmail.com','9123456788',1,'male');
insert into Patient_Details values(03,'anu','#14mangalore','anu@gmail.com','9123456787',1,'female');
insert into Patient_Details values(04,'ram','#124manipal','ram@gmail.com','9123456786',1,'male');
insert into Patient_Details values(05,'raj','#125manipal','raj@gmail.com','9123456785',1,'male');





insert into Medical_History values(01,'fever','amoxaline');
insert into Medical_History values(02,'cold','paracetomol');
insert into Medical_History values(03,'synus','walgreen');
insert into Medical_History values(04,'broken arm','volini');
insert into Medical_History values(05,'condution injury','zolo');






insert into Allergy_information values(01,01,'aquaphobia');
insert into Allergy_information values(02,05,'skin elergy');
insert into Allergy_information values(03,02,'rashes');
insert into Allergy_information values(04,03,'food allergy');
insert into Allergy_information values(05,04,'nausea');


