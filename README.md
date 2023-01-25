# Minitalk

*Version: 2*

## Grade - 125/100

Mandatory Part : 100/100  
Bonus Part : 25/25

## Description

The purpose of this project is to code a small data exchange program using UNIX signals.

## What's in this project

It was realized with all the bonuses. All the files are normed following the standard of 42.

This project contains the necessary Minitalk code to send message through signal between a server and one or many clients.

* includes

`minitalk.h`  

* srcs

`server.c`  
`client.c`  
`utils.c`  
`ft_atoi.c`  

* others

`Makefile`  

## How to use it

Create the executables : `server` and `client`.
```make```

## Testing

```javascript
make
```

This project respects the norm of 42 and has been tested with the norminette.  

This project has been tested with valgrind and contains no leaks.  
All tests return : `All heap blocks were freed -- no leaks are possible`.  
 
## Credit

Project made by [ffouquet42](https://github.com/ffouquet42)