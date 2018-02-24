<?php
header("Content-type:text/xml");
echo "<?xml version='1.0' encoding='UTF-8'>";
include("connect.php");
$sql = "SELECT * FROM user ";
$sql .= "WHERE 1 ORDER BY username";
$result = mysql_query($sql,$link);
echo "<data>";
while($row = mysql_fetch_array($result)){ 
echo "<user>";
echo "<username>".$row['usernmame']."</username>";
echo "<firstname>".$row['firstname']."</firstname>";
echo "<lastname>".$row['lastname']."</lastname>";
echo "<email>".$row['email']."</email>";
echo "<phone>".$row['phone']."</phone>";
echo "<register_date>".$row['register_date']."</register_date>";
echo "</user>";
}
echo "</data>";
?>
