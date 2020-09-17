FORMATTER = `\
    __________k00, __________k01, __________k02, __________k03, __________k04, __________k05, __________k06,      __________k60, __________k61, __________k62, __________k63, __________k64, __________k65, __________k66,
    __________k10, __________k11, __________k12, __________k13, __________k14, __________k15, __________k16,      __________k70, __________k71, __________k72, __________k73, __________k74, __________k75, __________k76,
    __________k20, __________k21, __________k22, __________k23, __________k24, __________k25, __________k26,      __________k80, __________k81, __________k82, __________k83, __________k84, __________k85, __________k86,
    __________k30, __________k31, __________k32, __________k33, __________k34, __________k35,                                    __________k91, __________k92, __________k93, __________k94, __________k95, __________k96,
    __________k40, __________k41, __________k42, __________k43, __________k44,                __________k53,      __________kb3,                __________ka2, __________ka3, __________ka4, __________ka5, __________ka6,
                                                                __________k50, __________k51, __________k52,      __________kb4, __________kb5, __________kb6`;

// Expected input form: { {h, s, v}, {h, s, v}, ... } - a C-style matrix initialization.
toHsvArray = (str) => JSON.parse(str.replaceAll('{', '[').replaceAll('}', ']'));

prettyValue = ([h, s, v]) => `{${[h,s,v].map(val => String(val).padStart(3, ' ')).join(',')}}`

INTAKE = [
  'k00', 'k10', 'k20', 'k30', 'k40',
  'k01', 'k11', 'k21', 'k31', 'k41',
  'k02', 'k12', 'k22', 'k32', 'k42',
  'k03', 'k13', 'k23', 'k33', 'k43',
  'k04', 'k14', 'k24', 'k34', 'k44',
  'k05', 'k15', 'k25', 'k35',
  'k06', 'k16', 'k26', 'k50',
  'k51',
  'k52',
  'k53',

  'k66', 'k76', 'k86', 'k96', 'ka6',
  'k65', 'k75', 'k85', 'k95', 'ka5',
  'k64', 'k74', 'k84', 'k94', 'ka4',
  'k63', 'k73', 'k83', 'k93', 'ka3',
  'k62', 'k72', 'k82', 'k92', 'ka2',
  'k61', 'k71', 'k81', 'k91',
  'k60', 'k70', 'k80', 'kb6',
  'kb5',
  'kb4',
  'kb3'
];

rawToMapped = (rawForm) => {
  const pretty = toHsvArray(rawForm).map(val => prettyValue(val));
  if (pretty.length !== INTAKE.length) throw new Error('Wrong input length');
  let i = 0;
  const formatted = String(FORMATTER).replace(
    // This means: look for tokens like __________k00 and keep the stuff between such tokens
    /([^kab0-9_]*)(_{10}k[ab0-9]{2})([^kab0-9_]*)/g,
    (_, prefix, paddedKeyId, suffix) => {
      const keyId = paddedKeyId.replaceAll('_', ''); // Now just something like k00
      const where = INTAKE.indexOf(keyId);
      if (where < 0) throw new Error('Input contains an unknown key id: ' + keyId);
      return `${prefix}${pretty[where]}${suffix}`;
    });
  return formatted;
}