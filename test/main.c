#include "yrc.h"
#include <stdio.h>
#include <string.h>
const char* msg = "try { x++ * y; x--; var abba = {get x: 3, [y]: 3, n}; } catch(err) { }; function hey() {}";

size_t readmsg(char* data, size_t desired, void* ctx) {
  static size_t idx = 0;
  static size_t cnt = 0;
  size_t i = 0;

  while(msg[idx] && i < desired) {
    data[i++] = msg[idx++];
  }

  if (!msg[idx] && cnt < 100) {
    ++cnt;
    idx = 0;
  }

  return i;
}

size_t readstdin(char* data, size_t desired, void* ctx) {
  static int cnt = 0;
  FILE* inp = (FILE*)ctx;
  if (feof(inp)) {
    if (cnt++ < 10) {
      fseek(inp, 0, SEEK_SET);
    } else {
      return 0;
    }
  }
  return fread(data, 1, desired, inp);
}

size_t readstr(char* data, size_t desired, void* ctx) {
  static int cnt = 0;
  static size_t pos = 0;
  static size_t len = 0;
  if (len == 0) len = strlen(ctx);
  if (pos == len) {
    if (cnt++ < 10) {
      pos = 0;
    } else {
      return 0;
    }
  }
  size_t read = desired < len - pos ? desired : len - pos;
  memcpy(data, ctx + pos, read);
  pos += read;
  return read;
}

int main(int argc, const char** argv) {
  FILE* inp = NULL;
  const char* filename;
  if (argc < 2) {
    filename = "/Users/chris/projects/personal/yrc/corpus/jquery.js";
  } else {
    filename = argv[1];
  }

  inp = fopen(filename, "r");
  if (inp == NULL) {
    printf("could not open %s\n", argv[1]);
    return 1;
  }
  yrc_parse_request_t req = {
    .read=readstdin,
    .readsize=16384,
    .readctx=inp
  };
  yrc_parse_response_t* resp;
  if (yrc_parse(&req, &resp)) {
    printf("bad exit\n");
  } else {
    yrc_parse_free(resp);
  }
  fclose(inp);
  return 0;
}
