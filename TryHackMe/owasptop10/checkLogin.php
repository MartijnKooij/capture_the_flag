	
<!DOCTYPE html>
<html>
	<head>
		<title>Login</title>
		<meta name="viewport" content="width=device-width, user-scalable=no">
		<meta charset="utf-8">
		<link rel="shortcut icon" type="image/x-icon" href="../favicon.ico">
		<link type="text/css" rel="stylesheet" href="../assets/css/style.css">
		<link type="text/css" rel="stylesheet" href="../assets/css/loginStyle.css">
		<link type="text/css" rel="stylesheet" href="../assets/css/orkney.css">
		<link type="text/css" rel="stylesheet" href="../assets/css/icons.css">
		<script src="../assets/js/jquery-3.5.1.min.js"></script>
		<script src="../assets/js/loginScript.js"></script>
	</head>
	<body>
		<header>
			<a id="home" href="/">Sense and Sensitivity</a>
			<a id="login" href="/login">Login</a>
		</header>
		<div class=background></div>
		<!-- Must remember to do something better with the database than store it in /assets... -->
		<main>
			<div class="content">
				<form method="POST" action="/api/login">
					<input type="text" name="username" placeholder="Username"><br>
					<input type="password" name="password" placeholder="Password"><br>
					<input id="loginBtnFunc" type="submit" value="Login!">
				</form>
				<i id="loginBtnStyle" class="material-icons">arrow_forward</i>
				<p class="responseMsg"  id="errorMsg">You don't have permission to access the console.</p>
			</div>
		</main>
		<footer><span>&copy; Sense and Sensitivity, 2020</span></footer>
	</body>
</html>
