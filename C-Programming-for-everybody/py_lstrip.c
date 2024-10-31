void py_lstrip(char *inp) {
	int pos, i = 0;
	int len = strlen(inp);
	// pos at end of whitespace
	while ((pos < len) && (inp[pos] == ' ' || inp[pos] == '\t' || inp[pos] == '\n')) {
		pos++;
	}
	// swap from pos to beggining
	while (pos < len) {
		inp[i++] = inp [pos++];
	}
	inp[i] = '\0';
}

