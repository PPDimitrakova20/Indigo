#pragma once

struct or0 {
	int type = 1; // Or with negative outcome
	bool outcome = false;
	int quantity = 8;
} cardOr0;


struct or1 {
	int type = 2; // Or with positive outcome
	bool outcome = true;
	int quantity = 8;
} cardOr1;

struct and0 {
	int type = 3; // And with negative outcome
	bool outcome = false;
	int quantity = 8;
} cardAnd0;

struct and1 {
	int type = 4; // And with positive outcome
	bool outcome = true;
	int quantity = 8;
} cardAnd1;

struct xor0 {
	int type = 5; // Xor with negative outcome
	bool outcome = false;
	int quantity = 8;
} cardXor0;

struct xor1 {
	int type = 6; // Xor with positive outcome
	bool outcome = true;
	int quantity = 8;
} cardXor1;

