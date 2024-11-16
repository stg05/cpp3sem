Base const *D1BaseToD2Base(Base const *base)
{
    D1 *d1ptr = (D1 *)base;
    D3 *d3ptr = (D3 *)d1ptr;
    D2 *d2ptr = (D2 *)d3ptr;
    Base *target_base = (Base *)d2ptr;
    return target_base;
}