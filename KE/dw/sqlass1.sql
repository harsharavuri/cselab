/*
1.	Find out the selling average cost for Packages developed in PASCAL.
*/
select round((sum(scost*sold)+sum(sold))/sum(sold)) from software where developing='PASCAL';
/*2.	Display the names ages of all programmers*/
select pname,round((sysdate-dob)/365) age from programmer;
/*3.	Display the names of those who have done the DAP course.*/
select pname from studies where course='dap';
/*4.	Display the names and date of births of all programmers born in January.*/
select pname,dob from programmer where dob like '%JAN%';
/*5.	What is the highest number of copies sold by a package*/
select max(sum(sold)) from software group by developing;
/*6.	Display the lowest course fee*/
select MIN(coursefee) from studies;
/*7.	How many programmers done the PGDCA course*/
select count(*) from studies where course='pgdca';
/*8.	How much revenue has been earned thru sales of packages developed in c.*/
/*9.	Display the details of the software developed by Ramesh.*/
select title,developing from software where pname='ramesh';
/*10.	How may programmers studied at Sabhari*/
select count(*) from studies where institute='sabhari';
/*11.	Display details of packages whose sales crossed the 2000 mark*/
select * from software where scost>2000;
/*12.	Find out the number of copies which should be sold in order to*/
/*13.	Display the details of packages for which developments cost have been recovered.*/
select * from software where (scost*sold)>dcost;
/*14.	What is the cost of the costliest software developed in basic */
select max(dcost) from software where developing='basic';
/*15.	How many packages developed in dbase*/
select COUNT(*) from software where developing='dbase';
/*16.	How many programmers studies in Pragathi*/
select count(*) from studies where institute='pragathi';
/*17.	How many programmers paid 5000 to 10000 for their studies.*/
select count(*) from studies where coursefee BETWEEN 5000 AND 10000;
/*18.	What is avg course fee*/
select avg(coursefee) from studies;
/*19.	Display the detail the programmers knowing c*/
select * from programmer where prof1='C' or prof2='C';
/*20.	How many programmers know either Cobol or Pascal*/
select count(*) from programmer where prof1='PASCAL' or prof1='COBOL' or prof2='PASCAL' or prof2='COBOL';
/*21.	How many programmers don’t know Pascal and c*/
select count(*) from programmer where prof1 not like 'PASCAL' and prof2 not like 'C' and prof2 not like 'PASCAL' and prof1 not like 'C'; 
/*22.	How old is the oldest male programmers*/
select pname,round((sysdate-dob)/365) as age from programmer where sex='M' and round((sysdate-dob)/365) like (select max(round((sysdate-dob)/365)) FROM programmer where sex='M');
/*23.	Calculate the experience in years for each programmers and. Display along with the names in descending order. */
select pname,round((sysdate - doj)/365) as experience from programmer order by (round(sysdate - doj)/365) desc;
/*24.	Who are the programmers who celebrate their birthdays during the current month.*/
select pname from programmer where dob like '%AUG%';
/*25.	How many female programmers are there*/
select COUNT(*) from programmer where sex='F';                                                                                                                                                                                                                                                         
/*26.	What are the languages by male programmers*/
select prof1 from programmer where sex='M' union select prof2 from programmer where sex='M';
/*27.	What is the average  salary*/
select avg(salary) from programmer;
/*28.	How many people draw salary 2000 to 4000 */
select pname from programmer where salary between 2000 and 4000;
/*29.	Display the details of those who don’t know clipper Cobol or Pascal*/
select * from programmer where prof1 not like 'CLIPPER' and prof1 not like 'COBOL' and prof1 not like 'PASCAL' and prof2 not like 'CLIPPER' and prof2 not like 'COBOL' and prof2 not like 'PASCAL';
/*30.	Display the cost of package developed by each programmer*/
select pname,sum(sold) from software group by pname;  

/*31.	Display the sales values of the packages developed by the each programmer*/
select scost, developing from software;
/*32.	Display the number of packages sold by each programmer.*/
select sum(sold)as packages from software;

/*33.	Display the sales cost of the packages developed by each programmer*/
select pname, scost*sold as sales_cost from software; 

/*34.	Display the sales cost of the packages developed by each programmer language wise*/
select pname as name,developing as language,sum(scost*sold) as sales_cost from software group by developing,pname;
/*35.	Display each language name with Average  development cost,  average selling cost and average  price per copy.*/
select developing,avg(scost),avg(dcost),(sum(scost)*COUNT(scost)/sum(sold))  from software group by developing;


/*36.	Display each programmers name costliest and cheapest packages developed by him or her .*/

/*37.	Display each institute name with number of courses average cost per course.*/

/*38.	Display each institute name with number of students.*/

/*39.	Display names of male and female programmers name and sex also */

/*40.	Display the name of programmers and their packages*/

/*41.	Display the number of packages in each languages except c and c++.*/
select count(title) from software where developing !='C' or developing!= 'CPP';

-----que43
/*43.	Display the average  difference between SCOST and DCOST for each package.*/
select min(scost-dcost)/count(title),count(title) from software group by title;

---que 44/*44.	Display the total SCOST, DCOST and amount to be recovered for each programmer for those whose DCOST has not yet been recovered.*/
select sum(scost),sum(dcost) from software where dcost>scost; 

-----que 45/*45.	Display the highest,  lowest  and average salaries for those earning more than 2000.*/

select max(salary),min(salary),avg(salary)"Average" from programmer where salary>2000;

----que 46/*46.	Who is the highest paid in c programmers.*/

select pname,salary from programmer where salary in (Select max(salary) from programmer where lower( prof1)='c' or lower(prof2)='c');

------que 47/*47.	Who is the highest paid female Cobol programmer*/

Select pname from programmer where salary in (select max(salary) from programmer where( sex='F' and (lower(prof1)='cobol' or lower(prof2)='cobol')));

---que 48/*48.	Display the names of the highest paid programmer for each language */
select DISTINCT pname,salary, prof1 from programmer where (salary,prof1) in(select max(salary), prof1 from programmer group by prof1);


----que 49/*49.	Who is the most experienced male programmer knowing Pascal*/

select floor ((sysdate-doj)/365)pname from programmer where floor((sysdate-doj)/365)=(select MAX(floor((sysdate-doj)/365) from programmer and(prof1 like 'PASCAL'or prof2 like 'PASCAL');
desc programmer
select * from programmer;
---------que 50/*50.	Who is the most experienced male programmer knowing Pascal*/
select pname,round(months_between(DOJ,DOB)/12)AS EXPERIENCE from programmer WHERE prof1='PASCAL'
and sex='M' and round(months_between(DOJ,DOB)/12) like (select max(round(months_between(DOJ,DOB)/12)) from programmer where prof1='PASCAL' or prof2='PASCAL' and sex='M' );



select pname from programmer where sex in (select max(months_between(Select sysdate from dual,doj)/12) from programmer where sex='M'); 

---que 51/*51.	Which language is known by only one programmer.*/
select prof1 from programmer group by prof1;

/*52.	Who is the above programmer referred in 51.*/
--que53/*53.	Who is the youngest programmer knowing dbase*/

select pname, min(months_between((select sysdate from dual),dob)/12)"youngest" from programmer where pname in(select pname FROM programmer where lower(prof1)='dbase' or lower(prof2)='dbase');
                
/*83.	Display the details of those who are drawing the same salary.*/
select pname,salary from programmer where salary=any(select salary from programmer p group by salary having salary=p.salary and COUNT(*)>1);              `