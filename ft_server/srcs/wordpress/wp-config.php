<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', 'tpgns120' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '[JBf9_w97g|*4#gt#c1+RKi0`Dd-)z^(av4qRg?5Pm]N=-<s;Utp=jT|~)MH=YuA');
define('SECURE_AUTH_KEY',  'S5+O-P7[BCx8C:3pu9Zk&BrwUVCg7xWfjIGuB_6+$$XGELT$70L.1)a<uK`CY+jM');
define('LOGGED_IN_KEY',    'A0},19.~va9SS9*KgoM[A>b|`/+XL`$pN-d;e.vQ,Cx4 ~qHa_Y%*YMMlb}Ccj[|');
define('NONCE_KEY',        'WN?X<hBgGVt2I`+r2O$UVrdeLY0M+d1%RO~9v1ca4Ku>Z<U|m A&6W?@Z[<JMf^b');
define('AUTH_SALT',        'YAOu9}4b9&&p5Q&5 fT)O#&m!#bQAl3--qw:edhH@8M$F|&LF4iJir;5=+!.L!yo');
define('SECURE_AUTH_SALT', 'AaZw@9dxZ@pm,mFM#idt/(zPu-.mcsUQkK>Q,4 +[NhuZ|)*z:6^U:N5[sc8@CzC');
define('LOGGED_IN_SALT',   'Vq:%P,X*gq0wZ-FAbT,9%pRKXp[z|~+OX{pKk,^M=] ;u$AmlXmJMxs>F7zW>ZRc');
define('NONCE_SALT',       '7Re[-*JSy?WDM$x}gUb1wlL<-R``V#NEG(zrd5U#%ly|o!uK.m=R`Q/L|N|].&^)');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
