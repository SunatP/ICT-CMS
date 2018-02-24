<?
require_once("contest.php");
header( 'Content-Type:text/html; charset=utf-8');
$username = $_POST['username'];
$password = $_POST['password'];
$firstname = $_POST['firstname'];
$lastname = $_POST['lastname'];
$email = $_POST['email'];
$phone = $_POST['phone'];
$sql = "INSERT INTO user (username,password,firstname,lastname,email,phone)";
$sql .= "VALUES ('$username','$password','$firstname','$lastname','$email','$phone')";
$result = mysql_query($sql,$link);
if($result)
{
    die ('Could not connect: ' . mysql_error());
}
else
{
    echo "<br> SP Con To Sign UP OK!";
}
?>