using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SetSettings : MonoBehaviour
{
  public void ustaw_rozmiar(float ROZMIAR)
    {
        Settings.ROZMIAR = (int)ROZMIAR;
    }

    public void ustaw_wygrana(float WYGRANA)
    {
        Settings.WYGRANA = (int)WYGRANA;
    }
}
