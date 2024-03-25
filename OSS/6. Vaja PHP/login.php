<?php
include('database.php');
session_start();

if($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    foreach($users as $user) {
        if($user['username'] == $username && $user['password'] == $password) {
            $_SESSION['username'] = $username;
            header("Location: index.php");
            exit;
        }
    }
    echo "Napačno uporabniško ime ali geslo.";
}
?>
<html>
<body>
    <form action="login.php" method="POST">
        Uporabniško ime: <input type="text" name="username"><br>
        Geslo: <input type="password" name="password"><br>
        <input type="submit" value="Prijava">
    </form>
</body>
</html>
