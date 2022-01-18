using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(Button))]
public class FirstButton : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
#if !UNITY_ANDROID && !UNITY_IOS
        //select button to allow navigating with keyboard/controller
        GetComponent<Button>().Select();
#endif
    }
}
