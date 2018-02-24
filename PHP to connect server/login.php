<?
require_once("connect.php");
$username = $_POST['username'];
$password = $_POST['password'];
$sql = "SELECT * FROM user ";
$sql .= "WHERE username='$username' AND password = '$password'";
$result = mysql_query($sql,$link);
$count = mysql_num_rows($result);
if($count > 0 ){
    echo " Login OK!";
}
else {
    echo " Fail";
}
