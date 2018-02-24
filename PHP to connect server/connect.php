<?php
$link=mysql_connect("localhost","root","1234");
mysql_select_db("db_user",$link);
mysql_query("SET NAMES UTF8");
if($link)
{
echo "Connection OK!";
}
else
{
echo "Connect Fail";
}
?>